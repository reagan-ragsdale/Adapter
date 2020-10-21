#include <iostream>

using namespace std;

class Bird { 
	// birds implement Bird interface that allows 
	// them to fly and make sounds adaptee interface 
	public:
		virtual	void fly() = 0; 
		virtual void makeSound() = 0; 
}; 

class Sparrow: public Bird { 
	// a concrete implementation of bird 
	public:
		void fly() { 
			cout << "Flying\n"; 
		} 
		void makeSound() { 
			cout << "Chirp Chirp\n"; 
		} 
}; 

class ToyDuck { 
	// target interface 
	// toyducks dont fly they just make 
	// squeaking sound 
	public:
		virtual void squeak() = 0; 
}; 

class PlasticToyDuck: public ToyDuck { 
	public:
		void squeak() { 
			cout << "Squeak\n"; 
		} 
};

class BirdAdapter: public ToyDuck { 
	// You need to implement the interface your 
	// client expects to use. 
	Bird* bird; 
	public:
		BirdAdapter(Bird* new_bird) { 
			// we need reference to the object we 
			// are adapting 
			bird = new_bird; 
		} 

		void squeak() { 
			// translate the methods appropriately 
			bird->makeSound(); 
		} 
};

int main() { 
	Sparrow* sparrow = new Sparrow; 
	ToyDuck* toyDuck = new PlasticToyDuck; 

	// Wrap a bird in a birdAdapter so that it 
	// behaves like toy duck 
	ToyDuck* birdAdapter = new BirdAdapter(sparrow); 

	cout << "Sparrow...\n"; 
	sparrow->fly(); 
	sparrow->makeSound(); 

	cout << "ToyDuck...\n"; 
	toyDuck->squeak(); 

	// toy duck behaving like a bird 
	cout << "BirdAdapter...\n"; 
	birdAdapter->squeak(); 
}