#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Aircraft //simple record class which holds information (fields) for a singluar aircraft
{
    private:
        string name;
        string type;
        string countryOfOrigin;
        int weight; //metric
        int topSpeed; //km/h

    public:
        Aircraft() //default constructor
        {
            name = "";
            type = "";
            countryOfOrigin = "";
            weight = 0;
            topSpeed = 0;
        }

        string getName() const //returns the name of the aircraft
        {
            return name;
        }

        void setName(string s) //sets the name of the aircraft
        {
            name = s;
        }

        string getType() const //returns the type of the aircraft
        {
            return type;
        }

        void setType(string s) //sets the type of the aircraft
        {
            type = s;
        }

        string getCountry() const //returns the country of origin of the aircraft
        {
            return countryOfOrigin;
        }

        void setCountry(string s) //sets the country of origin of the aircraft
        {
            countryOfOrigin = s;
        }

        int getWeight() const //returns the the weight of the aircraft
        {
            return weight;
        }

        void setWeight(int num) //sets the weight of the aircraft
        {
            weight = num;
        }

        int getSpeed() const //returns the top speed of the aircraft
        {
            return topSpeed;
        }

        void setSpeed(int num) //sets the top speed of the aircraft
        {
            topSpeed = num;
        }

        virtual ~Aircraft() //virtual destructor
        {
            //empty because no dynamic memmory allocation was used
        }
};
