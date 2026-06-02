const express = require("express");

const router = express.Router();

router.get("/", (req, res) => {

    res.send("Emergency route reachable");

});

router.post("/", (req, res) => {

    console.log("Emergency event received!");

    console.log(req.body);

    res.status(200).json({
        success: true,
        message: "Emergency event received successfully"
    });
});

module.exports = router;