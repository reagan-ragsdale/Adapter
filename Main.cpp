#include <iostream>

using namespace std;

class BigCat { 
	// birds implement Bird interface that allows 
	// them to fly and make sounds adaptee interface 
	public:
		virtual	void run() = 0; 
		virtual void makeSound() = 0; 
}; 

class Lion: public BigCat { 
	// a concrete implementation of bird 
	public:
		void run() { 
			cout << "Running\n"; 
		} 
		void makeSound() { 
			cout << "Roar\n"; 
		} 
}; 

class Cat { 
	// target interface 
	// toyducks dont fly they just make 
	// squeaking sound 
	public:
		virtual void meow() = 0; 
    virtual void prance() = 0;
}; 

class BabyCat: public Cat { 
	public:
		void meow() { 
			cout << "Meow\n"; 
		} 
    void prance() {
      cout << "Prancing\n";
    }
};

class CatAdapter: public Cat { 
	// You need to implement the interface your 
	// client expects to use. 
	BigCat* bigcat; 
	public:
		CatAdapter(BigCat* new_cat) { 
			// we need reference to the object we 
			// are adapting 
			bigcat = new_cat; 
		} 

		void meow() { 
			// translate the methods appropriately 
			bigcat->makeSound(); 
		} 

    void prance(){
      bigcat->run();}
};

int main() { 
	Lion* lion = new Lion; 
	Cat* babyCat = new BabyCat; 

	// Wrap a bird in a birdAdapter so that it 
	// behaves like toy duck 
	Cat* catAdapter = new CatAdapter(lion); 

	cout << "Lion...\n"; 
	lion->run(); 
	lion->makeSound(); 

	cout << "Baby Cat...\n"; 
	babyCat->meow(); 
  babyCat->prance();

	cout << "CatAdapter...\n";
  catAdapter->prance(); 
	catAdapter->meow(); 
}