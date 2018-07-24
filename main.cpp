#include <iostream>
#include <vector>
#define VUNIT 22
struct Rectangule {};
struct DesignModule : public Rectangule
{
    DesignModule() = default;
    virtual ~DesignModule() = default;
};
class PDR
{
    using Size = std::size_t;
    Size hight, width;

    using countDM = std::vector<DesignModule*>;
    countDM dm;

    using Area = uint; Area area = 0;

    using Table = bool**;
    Table b_table;

    using Hight = int;
    Hight c_hight ()
    {
        if (area <= 4)
            return 1;
        else if(area >= 5 and area <= 16)
            return 2;
        else if(area >= 257 and area <= 1024)
            return 16;
        else
            return 0;
    }
public:
    PDR(const Size hight, const Size width) : hight(hight), width(width)
    {
        b_table = new bool*[hight];
        for(int i = 0; i < hight; i++)
            b_table[i] = new bool[width];
        for(auto y = 0; y < hight ; y++)
        {
            for(auto x = 0; x < width; x++)
            {
                b_table[y][x] = false;
            }
        }
    }
    using Position = uint;
    void newModule(Position y, Position x)
    {
        if(x < width and y < hight)
        {
            b_table[y][x] = true;
            dm.push_back(new DesignModule());
            area++;
        } else
        {
            std::cout << "[ERROR]: The positions(x,y) are out of range" << '\n';
        }
    }
    ~PDR()
    {
        for(int i = 0; i < hight; i++)
            delete[] b_table[i];
        delete[] b_table;
    }
    using Cost = uint;Cost t_cost()
    {
        return ((dm.size()*(this->c_hight()))*VUNIT);
    }
    void printPDR()
    {
        for(auto y = 0; y < hight ; y++)
        {
            for(auto x = 0; x < width; x++)
            {
                if(b_table[y][x])
                    std::cout <<  "****";
                else
                    std::cout << "    ";
            }
            std::cout << "\n";
        }
    }
    Area getCount() {return area;}
    Hight getHight(){return c_hight();}
};

int main(int argc, char const *argv[]) {
    PDR pdr2(3,3);
    pdr2.newModule(1,0);
    pdr2.newModule(1,1);

    pdr2.newModule(0,2);
    pdr2.newModule(1,2);
    pdr2.newModule(2,2);

    std::cout<<"Cantidad de Módulos: " << pdr2.getCount() << std::endl
             <<"Altura PDR: " << pdr2.getHight() << std::endl
             <<"Costo: $" <<pdr2.t_cost() << std::endl
             <<"Forma del objeto: \n"; pdr2.printPDR();

    return 0;
}
