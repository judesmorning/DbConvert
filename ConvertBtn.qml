import QtQuick 2.0
import QtQuick.Controls 2.2

ComboBox {
    model: [
        "dBm to mW", "mW to dBm",
        "dBm to Watt", "Watt to dBm",
        "dBm to Vrms", "Vrms to dBm",
        "dBm to dBmV", "dBmV to dBm",
        "dBm to dBuV", "dBuV to dBm"
    ]
}
