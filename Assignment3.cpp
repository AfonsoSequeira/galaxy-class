//Assignment3 Galaxies 
//Afonso Sequeira ID:10139091
//09/03/2021

#include<iostream>
#include<vector>
#include<string>

//create a class to store galaxy objects
class galaxy
{   
    private:
        std::string hubble_type{"not specified"};
        double redshift{0.0};
        double total_mass{0.0};
        double stellar_mass_fraction{0.0};
        std::vector<galaxy> satellites;
    
    public:
        //constructors (default and parametrized)
        galaxy() = default;
        galaxy( std::string g_hubble_type, double g_redshift, double g_total_mass, 
            double g_stelar_mass_fraction ) : 
            hubble_type{g_hubble_type}, redshift{g_redshift}, total_mass{g_total_mass},  
            stellar_mass_fraction{g_stelar_mass_fraction} {}

        //destructor
        ~galaxy() {}

        //function to print all data for the object
        void print_data();

        //setter and getter function for hubble_type
        void set_type(std::string& gtype) {hubble_type = gtype;}
        std::string get_type() {return hubble_type;}

        //setter and getter for redshift
        void set_redshift(double gredshift) {redshift = gredshift;}
        double get_redshift() {return redshift;}

        //setter and getter for total mass
        void set_total_mass(double gmass) {total_mass = gmass;}
        double get_total_mass() {return total_mass;}

        //setter and getter for stellar mass fraction
        void set_stellar_mass_fraction(double gstellar) {stellar_mass_fraction = gstellar;}
        double get_stellar_mass_fraction() {return stellar_mass_fraction;}

        //function to return stellar mass
        double stellar_mass() {return stellar_mass_fraction * total_mass;}

        //function to add satellite to vector of satellites of the object
        void add_satellite(galaxy& gal) {
            satellites.push_back(gal);
        }


};

//implementation of print_data() function. If object has satellites, the function will print the data
//for these as well
void galaxy::print_data() {
    std::cout << "\nGalaxy Data:\n Hubble type: " << hubble_type
            << "\n Redshift: " << redshift << "\n Total Mass: " << total_mass 
            << "\n Stellar mass fraction: " << stellar_mass_fraction 
            << "\n Number of satellite galaxies: " << satellites.size() << std::endl;

    if (satellites.size() != 0) {
        std::cout << "\nSatellite Data:" << std::endl;
        for (auto satellites_it = satellites.begin(); satellites_it < satellites.end(); ++ satellites_it) {
            satellites_it -> print_data();
        }
        std::cout << "End of satellite data." <<std::endl;
    }
}

//main function
int main () {
    //create 3 galaxy objects
    galaxy galaxy1("SBc",0, 1e12 , 0.0334);
    galaxy galaxy2("Sa", 0.000804, 1e12, 0.035);
    galaxy galaxy3;
    //use setter and getter functions to set and print type of galaxy3
    std::string type = "E0";
    galaxy3.set_type(type);
    std::cout << "Galaxy 3 is of type: " << galaxy3.get_type() << std::endl;
    //print out stellar mass using member function stellar_mass()
    std::cout << "Galaxy 1 stellar mass is: " << galaxy1.stellar_mass() << std::endl;

    //create 2 more galaxy objects we will use as satellites
    galaxy large_mag_cloud("SBc", 0.00093, 10e9, 0.04);
    galaxy small_mag_cloud("SBa", 0.000527, 3e9, 0.01);
    galaxy1.add_satellite(large_mag_cloud);
    galaxy1.add_satellite(small_mag_cloud);
    
    //create vector to contain galaxies 1 to 3
    std::vector<galaxy> galaxy_vector;
    galaxy_vector.push_back(galaxy1);
    galaxy_vector.push_back(galaxy2);
    galaxy_vector.push_back(galaxy3);
    //iterate through vector and print data for each object 
    for (auto galaxy_it = galaxy_vector.begin(); galaxy_it < galaxy_vector.end(); ++  galaxy_it) {
        galaxy_it -> print_data();
    }
    return 0;
}