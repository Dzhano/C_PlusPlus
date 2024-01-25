#pragma once

enum type {
    critical,
    medium,
    normal,
    low
};

class Alert {
private:
    type alertType;
    double severity;
public:
    Alert(type, double);

    type getAlertType() const;
    double getSeverity() const;
};