const express = require("express");
const { WebSocketServer } = require("ws");

const app = express();
const PORT = 3001;

// Serve static files from frontend
app.use(express.static("../frontend"));

const server = app.listen(PORT, "0.0.0.0",() => {
    console.log(`Server running on ${PORT}`);
});

// WebSocket server for signaling
const wss = new WebSocketServer({ server });

wss.on("connection", (socket) => {
    console.log("New client connected");

    socket.on("message", (message) => {
        console.log("Received:", message);
        wss.clients.forEach((client) => {
            if (client !== socket && client.readyState === 1) {
                client.send(message);
            }
        });
    });

    socket.on("close", () => {
        console.log("Client disconnected");
    });
});
