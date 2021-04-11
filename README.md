# galaxy-class
A C++ class for describing galaxies.

- A galaxy object should contain the following (private) data:
  - Hubble type: string or alternatively an enum. Allow for the simplified classification in terms of E0 to E7, S0, Sa, Sb, Sc, SBa, SBb, SBc and Irr
    Redshift: double z in the range [0,10]
  - Total mass: double Mtot in the range [107,1012]M⊙
  - A stellar mass fraction: double f∗=M∗/Mtot in the range [0,0.05]
- The class should also contain several member functions (detailed below).
- The main() function should demonstrate use of the class through declaring and using objects

Your class should include:
 - A default constructor; a parameterized constructor; a destructor; (0.5 mark)
 - A member function (with definition outside the class) to print out an object’s data and a member function to change the galaxy’s Hubble type.
 - A member function to return the stellar mass M∗=f∗Mtot.
 - Your main() function should demonstrate the use of all of the above:
 - It should use a vector to store at least 2 different objects of sufficient complexity and use an iterator to access these objects and print their content.

Galaxies contain satellites (e.g. Milky Way has large and small Magellanic Clouds). Modify your class so each galaxy object can have satellites, as follows:
 - Include a private vector object inside your class to store satellites (which are galaxy objects)
 - Add a new member function to add a satellite galaxy
 - Modify your print function to print the number of satellites and, if non-zero, print their properties as well
 - Again, the functionality must be demonstrated in your main program.
