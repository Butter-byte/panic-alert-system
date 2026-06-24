let lastEmergencyTimestamp = 0;

const COOLDOWN_MS = 10 * 1000; // 10 seconds cooldown

const express = require("express");

const router = express.Router();

router.get("/", (req, res) => {

    res.send("Emergency route reachable");

});

router.post("/", (req, res) => {

    const now = Date.now();

    if(now - lastEmergencyTimestamp < COOLDOWN_MS) {

        console.log("PANIC REJECTED: COOLDOWN ACTIVE");

        return res.status(200).json({
            success: false,
            message: "Cooldown active"
        });
    }

    lastEmergencyTimestamp = now;

    console.log("PANIC ACCEPTED");

    console.log(req.body);

    return res.status(200).json({
        success: true,
        message: "Emergency accepted"
    });
});

module.exports = router;