#include "Alert.h"

Alert::Alert(type t, double severity) {
    this->alertType = t;
    this->severity = severity > 0 and severity < 11 ? severity : 1;
}

type Alert::getAlertType() const {
    return alertType;
}
double Alert::getSeverity() const {
    return severity;
}