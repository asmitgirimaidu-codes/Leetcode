class Robot {
public:
    int w, h, per;
    int x, y;
    int dir;
    bool moved;

    vector<string> name = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
        x = 0;
        y = 0;
        dir = 0;      // East
        moved = false;
    }

    void step(int num) {
        if (per == 0) return;

        moved = true;
        num %= per;

        if (num == 0) {
            if (x == 0 && y == 0)
                dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int d = (w - 1) - x;
                if (d >= num) {
                    x += num;
                    num = 0;
                } else {
                    x = w - 1;
                    num -= d;
                    dir = 1;
                }
            } else if (dir == 1) { // North
                int d = (h - 1) - y;
                if (d >= num) {
                    y += num;
                    num = 0;
                } else {
                    y = h - 1;
                    num -= d;
                    dir = 2;
                }
            } else if (dir == 2) { // West
                int d = x;
                if (d >= num) {
                    x -= num;
                    num = 0;
                } else {
                    x = 0;
                    num -= d;
                    dir = 3;
                }
            } else { // South
                int d = y;
                if (d >= num) {
                    y -= num;
                    num = 0;
                } else {
                    y = 0;
                    num -= d;
                    dir = 0;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (!moved) return "East";
        return name[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */