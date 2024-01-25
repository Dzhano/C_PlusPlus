#include <iostream>
#include "Alert.h"

int main()
{
    Alert alerts[10] = { { , }, { , }, { , }, { , }, { , },
        { , }, { , }, { , }, { , }, { , } };

    displayAlerts(alerts, 10, normal, 4);
}

void displayAlerts(Alert arr[], int size, type atype, int asev) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getAlertType() == atype && arr[i].getSeverity() == asev)
            std::cout << arr[i].getAlertType() << " " << arr[i].getSeverity() << std::endl;
    }
}