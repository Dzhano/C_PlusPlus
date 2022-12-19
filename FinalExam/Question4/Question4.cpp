#include <iostream>

class Player {
public:
    virtual int getPower() const = 0;
    virtual int getSkill() const = 0;
};

class GolfPlayer : Player {
private:
    int power, skill;
public:
    GolfPlayer() {
        setPower(0);
        setSkill(0);
    }

    GolfPlayer(int power, int skill) {
        setPower(power);
        setSkill(skill);
    }


    void setPower(int p) {
        power = p >= 0 ? p : 0; // I do not know if it is necessary but I am adding it as a logic.
    }

    int getPower() const {
        return power;
    }


    void setSkill(int s) {
        skill = s >= 0 ? s : 0; // I do not know if it is necessary but I am adding it as a logic.
    }

    int getSkill() const {
        return skill;
    }
};

int main()
{
    GolfPlayer player(12, 34);
    std::cout << "Power of the golf player: " << player.getPower() << std::endl;
    std::cout << "Skill of the golf player: " << player.getSkill() << std::endl;
}