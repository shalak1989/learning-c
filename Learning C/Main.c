#include <stdio.h>

void doSomethingWithOperators()
{
  int x = 5, y = 5;
  x += y;

  //assignment operator =
  //c will not stop invalid assignment, assining
  //a string to an int will give the numeric
  //+, -, *, /, % just like in C#
  // +=, *=, /=, -=, ++, +=
  //++x will increment BEFORE assignment
  //x++ will increment AFTER assignment which is why x++ works in loops in C#
  //C does have ternary
  //you have the not operator which flips bits: !x returns opposite
  //bitwise operators exist too.


  printf("Result is: %d\n", x % 2);
}

void controlFlow(int x)
{
  if (x == 1) {
    printf("TRUE\n");
  }
  else {
    printf("FALSE\n");
  }
}

int halveInt(int x) {
  return x / 2;
}
//
//for (x = 0; x < 100; x++) {
//
//}

//arrays
void arrayRun()
{
  int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
  int indexZero = array[0];
  array[0] = 145;

  //you can throw a const on the array to
  //prevent modificaton of a reference passed into a func
}

//kind of like objects but not really, stored on stack
 typedef struct {
  int x, y;
  short life;
  char *name;
 } Man;

 //could also do
 struct Man2 {
   int x, y;
};

void structs() 
{
  //two ways to initialize
  Man man = { 0, 0, 100, "name" }; //risky due to ordinal
  //better way
  Man man2;
  //way without typedef
  struct Man2 man3;
  man.x = 50;
  man.y = 50;
  man.life = 100;
  man.name = "a man";
  //creating a array of man
  Man manArray[100];
  for (int i = 0; i < 100; i++)
  {
    if (i < 50) {
      manArray[i].x = 0;
    }
    else {
      manArray[i].x = 200;
    }
    manArray[i].y = i * 5;
    manArray[i].life = 100;
    manArray[i].name = "man";
  }

}

//switch statements present as well

void doAllTheThings() {
  doSomethingWithOperators();
  //controlFlow(2);
  //printf("%d\n", halveInt(2));
  //getchar() is built in C function, looks like you can override it by redefining it
  //getchar();
  //Man man;
}
int main()
{
  doAllTheThings();
  return 0;
}
