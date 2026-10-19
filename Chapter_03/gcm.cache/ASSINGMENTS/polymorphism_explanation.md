EXPLANATION
The Payment class contains a virtual member function called pay().
MobileMoney and BankCard override the pay() function.
The pointer payment is a base-class pointer that can point to objects of either derived class.
When payment->pay() is called, C++ executes the version belonging to the actual object.
The same function call therefore produces different behaviour depending on the object. This is runtime polymorphism.