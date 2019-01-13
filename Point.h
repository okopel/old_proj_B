
#ifndef PROJB_POINT_H
#define PROJB_POINT_H

namespace project {
    class Pointm {
    private:
        int x;
        int y;
        int cost;
    public:
        Pointm(int x, int y, int cost) : x(x), y(y), cost(cost) {}

        /**
        * compare points by position
        * @param other the other point
        * @return true if equal
        * note: the comp doest calculate cost
        */
        bool operator==(Pointm *other) {
            return this->operator==(*other);
        }

        bool operator==(Pointm other) {
            return ((this->x == other.getX()) && (this->y == other.getY()));
        }

        int getX() const {
            return x;
        }

        void setX(int x) {
            Pointm::x = x;
        }

        int getY() const {
            return y;
        }

        void setY(int y) {
            Pointm::y = y;
        }

        int getCost() const {
            return cost;
        }

        void setCost(int cost) {
            Pointm::cost = cost;
        }
    };
}

#endif //PROJB_POINT_H
