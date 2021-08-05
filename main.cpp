#include<iostream>
using namespace std;
class vehicle{
protected://protected para poder acceder a estas variables desde las clases derivadas de esta
    string license;//caracteristicas que heredaran las clases car bike y truck
    int year;
public:
    vehicle(const string& mylicense, const int myyear)//constructor para la clase vehicle
        : license(mylicense), year(myyear){};//license=mylicense; year=myyear
    const string getlicense()const{//Poder ver los valores de las variables en la pantalla
        return license;
    }
    const int getyear()const{
        return year;
    }
};
class car:public virtual vehicle{//Crea una clase carro que hereda caracteristicas de la clase vehicle; se usa virtual para evitar el problema del diamante mas adelante
protected:
    string type;
public:
    car(const string& mylicense, const int myyear,const string& mytype)
        : vehicle(mylicense,myyear), type(mytype){};
    const string gettype()const{
        return type;
    }
};
class bike:public virtual vehicle{
protected:
    string style;
public:
    bike(const string& mylicense, const int myyear,const string& mystyle)
        : vehicle(mylicense,myyear), style(mystyle){};
    const string getstyle()const{
        return style;
    }
};
class truck:public virtual car, public virtual bike{
private://private ya que esta clase no hereda a nadie y solo se accede a esta variable desde esta esta clase
    string sizes;
public:
    truck(const string& mylicense, const int myyear,const string& mytype,const string& mystyle,const string& mysizes)
        : vehicle(mylicense,myyear),car(mylicense,myyear,mytype),bike(mylicense,myyear,mystyle), sizes(mysizes){};
    const string getsizes()const{
        return sizes;
    }
};
int main(){
    truck mytruck("as1231",1993,"Deportivo","Subaru","mediano");
    cout<<"Registro de su Vehiculo"<<endl;
    cout<<"Su licencia es:"<<" "<<mytruck.getlicense()<<"\n";
    cout<<"El año de fabricacion es:"<<" "<<mytruck.getyear()<<"\n";
    cout<<"El tipo de carro es:"<<" "<<mytruck.gettype()<<"\n";
    cout<<"La marca del carro:"<<" "<<mytruck.getstyle()<<"\n";
    cout<<"El tamaño del carro es:"<<" "<<mytruck.getsizes()<<"\n";
    return 0;
}
