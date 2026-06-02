const express = require("express");

const emergencyRoutes = require("../routes/emergencyRoutes");

const app = express();

const PORT = process.env.PORT || 3000;

app.use(express.json());

app.use("/emergency", emergencyRoutes);

app.get("/", (req, res) => {
    res.send("Panic Alert Backend Running");
});

console.log("=== PANIC ALERT BACKEND STARTED ===");

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});