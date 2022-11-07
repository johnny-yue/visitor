# visitor pattern 

In two different methods.
1. Classical method.
- The classical double dispatch implimentation. Requires two virtual function calls.
2. Using lambda, std::visit and std::variant
- Tested under a contrived example, it takes more time then a typical double dispatch. Possibly because the utility provided by std library has heavy internals.
- One thing this method is better than the first method is that it does not require the visited to be under the same type hierarchy.


## Compile / Run

mkdir bld

cd bld

cmake ..

make
