#include <iostream>
using namespace std;

class Base {
private:
    int privateData;

protected:
    int protectedData;

public:
    Base(int pData, int prData) : privateData(pData), protectedData(prData) {}

    // A method to show the data
    void showData() const {
        cout << "Private Data: " << privateData << ", Protected Data: " << protectedData << endl;
    }

    // Friend class declaration
    friend class FriendDerived;
};

class FriendDerived : public Base //frnd classas well asderived class
{
public:
    FriendDerived(int pData, int prData) : Base(pData, prData) {}

    void accessBaseMembers() {
        // Accessing protected member directly (allowed due to inheritance)
        cout << "Accessing Protected Data from Base: " << protectedData << endl;

        // Accessing private member directly (allowed due to friendship)
        cout << "Accessing Private Data from Base: " << privateData << endl;
    }
};

int main() {
    FriendDerived obj(10, 20);
    obj.showData(); // Show initial data
    obj.accessBaseMembers(); // Access and show data through friend class

    return 0;
}
