<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web SIP Client</title>
</head>
<body>
    <h2>Web SIP Client</h2>

    <!-- User input fields for SIP credentials -->
    <label>SIP Username: <input type="text" id="sipUser" placeholder="e.g. 1001"></label><br>
    <label>SIP Password: <input type="password" id="sipPassword"></label><br>
    <label>SIP Domain: <input type="text" id="sipDomain" placeholder="your.sip.domain"></label><br>
    <label>SIP Server: <input type="text" id="sipServer" placeholder="wss://your.asterisk.server:5066"></label><br>
    
    <button onclick="register()">Register</button>

    <hr>

    <!-- Call controls -->
    <label>Call SIP Number: <input type="text" id="callNumber" placeholder="e.g. 1002"></label>
    <button onclick="makeCall()">Call</button>
    <button onclick="hangup()">Hang Up</button>

    <hr>

    <!-- Incoming call UI -->
    <div id="incoming-call" style="display: none;">
        <h3>Incoming Call from <span id="callerID"></span></h3>
        <button onclick="acceptCall()">Accept</button>
        <button onclick="rejectCall()">Reject</button>
    </div>

    <!-- Audio output for SIP calls -->
    <audio id="remoteAudio" autoplay></audio>

    <!-- Include SIP.js library -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/sip.js/0.20.0/sip.min.js"></script>
    <script>
        let userAgent, session;

        // Function to register the SIP user agent
        function register() {
            const SIP_USER = document.getElementById("sipUser").value;
            const SIP_PASSWORD = document.getElementById("sipPassword").value;
            const SIP_DOMAIN = document.getElementById("sipDomain").value;
            const SIP_SERVER = document.getElementById("sipServer").value;

            userAgent = new SIP.UserAgent({
                uri: `sip:${SIP_USER}@${SIP_DOMAIN}`,
                transportOptions: { server: SIP_SERVER },
                authorizationUsername: SIP_USER,
                authorizationPassword: SIP_PASSWORD,
                sessionDescriptionHandlerFactoryOptions: {
                    constraints: { audio: true, video: false }
                }
            });

            userAgent.start().then(() => {
                console.log("Registered as " + SIP_USER);

                // Handle incoming calls properly
                userAgent.on("invite", (incomingSession) => {
                    session = incomingSession;
                    document.getElementById("incoming-call").style.display = "block";
                    document.getElementById("callerID").textContent = session.remoteIdentity.uri.toString();
                    console.log("Incoming call from: " + session.remoteIdentity.uri.toString());
                });
            }).catch(error => console.error("Registration failed", error));
        }

        // Function to make an outgoing call
        function makeCall() {
            const target = document.getElementById("callNumber").value;
            if (!target) {
                alert("Enter a SIP number to call!");
                return;
            }

            session = userAgent.invite(`sip:${target}@${userAgent.configuration.uri.host}`);

            session.on("accepted", () => {
                console.log("Call established");
                setupAudio(session);
            });

            session.on("terminated", () => {
                console.log("Call ended");
                session = null;
            });
        }

        // Function to accept an incoming call
        function acceptCall() {
            if (session) {
                session.accept().then(() => {
                    console.log("Call accepted");
                    setupAudio(session);
                    document.getElementById("incoming-call").style.display = "none";
                });
            }
        }

        // Function to reject an incoming call
        function rejectCall() {
            if (session) {
                session.reject();
                console.log("Call rejected");
                document.getElementById("incoming-call").style.display = "none";
                session = null;
            }
        }

        // Function to hang up an ongoing call
        function hangup() {
            if (session) {
                if (session.state === SIP.SessionState.Established) {
                    session.bye(); // Outgoing call
                } else {
                    session.terminate(); // Incoming call
                }
                console.log("Call ended");
                session = null;
            }
        }

        // Function to set up audio for an active session
        function setupAudio(session) {
            session.sessionDescriptionHandler.on("confirmed", () => {
                const remoteStream = new MediaStream();
                session.sessionDescriptionHandler.peerConnection.getReceivers().forEach(receiver => {
                    if (receiver.track) remoteStream.addTrack(receiver.track);
                });
                document.getElementById("remoteAudio").srcObject = remoteStream;
            });
        }
    </script>
</body>
</html>