#include<iostream>
#include<string>
using namespace std;


class clsAddress
{
    private:

        string _AddressLin1;
        string _AddressLin2;
        string _POBox;
        string _ZipCode;

    public:

        clsAddress() 
        {

        }

        clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
        {
            _AddressLin1 = AddressLine1;
            _AddressLin2 = AddressLine2;
            _POBox = POBox;
            _ZipCode = ZipCode;
        }
        clsAddress(clsAddress& old_obj)
        {
            _AddressLin1 = old_obj.AddressLiane1();
            _AddressLin2 = old_obj.AddressLine2();
            _POBox = old_obj.POBox();
            _ZipCode = old_obj.ZipCode();
        }
        void SetAddresssLine1(string AddressLine1)
        {
            _AddressLin1 = AddressLine1;
        }
        string GetAddressLine1()
        {
            return _AddressLine1
        }
        void SetAddresssLine2(string AddressLine2)
        {
            _AddressLin2 = AddressLine2;
        }
        string GetAddressLine1()
        {
            return _AddressLine2;
        }
        void SetPOBox(string POBox)
        {
            _POBox = POBox;
        }
        string GetPOBox()
        {
            return _POBox;
        }
        void SetZipCode(string ZipCode)
        {
            _ZipCode = ZipCode;
        }
        string GetZipCode()
        {
            return _ZipCode;
        }
        void Print()     
        {         
            cout << "\nAddress Details:\n";         
            cout << "------------------------";         
            cout << "\nAddressLine1: " << _AddressLine1 <<endl;         
            cout << "AddressLine2: " << _AddressLine2 << endl;         
            cout << "POBox       : " << _POBox << endl;         
            cout << "ZipCode     : " << _ZipCode << endl;     
        }

        __declspec(property(set=SetAddresssLine1, put=GetAddressLine1)) string AddressLine1;
        __declspec(property(set=SetAddresssLine2, put=GetAddressLine2)) string AddressLine2;
        __declspec(property(set=SetPOBox, put=GetPOBox)) string POBox;
        __declspec(property(set=SetZipCode, put=GetZipCode)) string ZipCode;
};


int main()
{
    clsAddress Address1("Sursuru Mah", "Yasam sk", "14/1 Elazig/Merkez", "23000");
    Address1.Print();
    
}