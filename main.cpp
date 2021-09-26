#include <bits/stdc++.h>
using namespace std;

int main() {
  string cmd;
  vector<pair<string, int>> data;
  int nearest=0, found=0;
  int n, age, slot;
  string regNo;
  while(1){
      found=0;
      cin>>cmd;
      if(cmd=="Create_parking_lot"){//case for creating n parking slot
            cin>>n;
            for(int i=0; i<n; i++){//making parking of n slots
              data.push_back(make_pair("",0));
            }
            cout<<"Created parking of "<<n<<" slots"<<endl;
      }else if(cmd=="Park"){//case for parking a car if a slot is available
            cin>>regNo;
            cin>>cmd;
            cin>>age;
            for(int i=0; i<n; i++){
              if(data[i].first == "" && data[i].second==0){
                nearest=i;
                found=1;
                break;
              }
            }
            if(found==0){cout<<"Parking is full \n";}
            else{
              data[nearest] = make_pair(regNo, age);
              cout<<"Car with vehicle registration number "<<data[nearest].first<<" has been parked at slot number "<<nearest + 1<<endl;
              found = 0;
            }
        
      }else if(cmd == "Slot_numbers_for_driver_of_age"){//case for displaying slot numbers of drivers of a given age if available
            cin>>age;
            for(int i=0; i<n; i++){
              if(data[i].second==age){
                cout<< i+1<<",";
                if(found==0){found=1;}
              }
            }
            if(found==0){cout<<"No driver of the given age has parked their car";}
            cout<<endl;
      }else if(cmd=="Slot_number_for_car_with_number"){//case for displaying slot no. of a car with a given registration number
            cin>>regNo;
            for(int i=0; i<n; i++){
              if(data[i].first==regNo){
                cout<< i+1<<endl;
                found=1;
                break;
              }
            }
            if(found==0){cout<<"Not found"<<endl;}
      }else if(cmd=="Leave"){//case when a car on a given slot leaves if the slot is not already empty 
            cin>>slot;
            if(slot>n){cout<<"This slot does not exist"<<endl;}
            else if(data[slot-1].first==""){
              cout<<"This parking slot is already empty"<<endl;
            }else{
              regNo = data[slot-1].first;
              age= data[slot-1].second;
              data[slot-1].first = "";
              data[slot-1].second=0;
              cout<<"Slot number "<<slot<<" vacated, the car with vehicle registration number "<<regNo<<" left the space, the driver of the car was of age "<<age<<endl;
            }
            
      }else if(cmd=="Vehicle_registration_number_for_driver_of_age"){//case for displaying vehicle registration number of a driver of a given age
            cin>> age;
            for(int i=0; i<n; i++){
              if(data[i].second==age){
                cout<< data[i].first <<",";
                if(found==0){found=1;}
              }
            }
            if(found==0){cout<<"No driver of the given age has parked their car";}
            cout<<endl;
      }else{//for a not valid comment
           cout<<"Not a valid command"<<endl;
      }
  }

}