#include <iostream>
#include <vector>

using namespace std;
struct Person {
    string name;
    float BMI;
};
void sortPersonsByBMI(const vector<Person> PERSONS_TO_SORT);
float calculateBMI(const float HEIGHT_IN_METERS,const float WEIGHT);
float convertCentimeteresToMeters(const int CENTIMETERS);
void loadDataFromInputToVector(vector<Person> &newPerson);
void displayAllPersonsName(const vector<Person> PERSONS);

int main() {
    vector<Person> personsToCheckBMI;
    loadDataFromInputToVector(personsToCheckBMI);
    sortPersonsByBMI(personsToCheckBMI);
}
void loadDataFromInputToVector(vector<Person> &persons) {
    int numberOfPersonsToLoad =0;
    cin>>numberOfPersonsToLoad;
    for(int i=1; i<=numberOfPersonsToLoad; i++) {
        int height, weight;
        Person newPerson;
        cin>>newPerson.name>>weight>>height;
        newPerson.BMI = calculateBMI(convertCentimeteresToMeters(height),weight);
        persons.push_back(newPerson);
    }
}
float convertCentimeteresToMeters(const int CENTIMETERS) {
    const float ONE_METER_IN_CENTIMETERS = 100;
    float meters = CENTIMETERS/ONE_METER_IN_CENTIMETERS;
    return meters;
}
float calculateBMI(const float HEIGHT_IN_METERS,const float WEIGHT) {
    return WEIGHT/(HEIGHT_IN_METERS*HEIGHT_IN_METERS);
}
void displayAllPersonsName(const vector<Person> PERSONS){
    const int AMOUNT_OF_PERSONS = PERSONS.size();
    for(int i=0; i<AMOUNT_OF_PERSONS;i++)
        cout<<PERSONS[i].name<<endl;
}
void sortPersonsByBMI(const vector<Person> PERSONS_TO_SORT) {
    vector<Person> personsWithTooLowBMI, personsWithTooHighBMI, personsWithBMIOK;
    const int HIGH_LIMIT_FOR_BMI_OK = 25,AMOUNT_OF_PERSONS=PERSONS_TO_SORT.size();
    const float LOW_LIMIT_FOR_BMI_OK=18.5;
    for(int i=0; i<AMOUNT_OF_PERSONS;i++) {
        if(PERSONS_TO_SORT[i].BMI<LOW_LIMIT_FOR_BMI_OK)
            personsWithTooLowBMI.push_back(PERSONS_TO_SORT[i]);
        else if(PERSONS_TO_SORT[i].BMI>=HIGH_LIMIT_FOR_BMI_OK)
            personsWithTooHighBMI.push_back(PERSONS_TO_SORT[i]);
        else
            personsWithBMIOK.push_back(PERSONS_TO_SORT[i]);
    }
    cout<<"niedowaga"<<endl;
    displayAllPersonsName(personsWithTooLowBMI);
    cout<<"wartosc prawidlowa"<<endl;
    displayAllPersonsName(personsWithBMIOK);
    cout<<"nadwaga"<<endl;
    displayAllPersonsName(personsWithTooHighBMI);
}
