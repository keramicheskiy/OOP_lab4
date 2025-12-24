#include "figure.h"
#include "array.h"
#include "hexagon.h"
#include "pentagon.h"
#include "octagon.h"
#include "point.h"


int main() {

    cout << "\nEnter figure array size: ";
    int size;
    cin >> size;
    Array<std::shared_ptr<Figure<double>>> vec;
    for (int i = 0; i < size; i++) {
        cout << "Choose a figure type:\n1 - Pentagon\n2 - Hexagon\n3 - Octagon" << endl;
        char c;
        cin >> c;
        std::shared_ptr<Figure<double>> f;
        if (c == '1') f = std::make_shared<Pentagon<double>>();
        else if (c == '2') f = std::make_shared<Hexagon<double>>();
        else if (c == '3') f = std::make_shared<Octagon<double>>();
        else continue;
        cout << fmt::format("Enter x and y with a space in between for every point of a {} !!!CLOCK WISE!!! and press Enter", f->name()) << endl;
        cin >> *f;
        cout << "Points you've entered: " << *f << endl;
        vec.push(f);
    }
    cout << "The entered array:" << endl;
    for (int i = 0; i < vec.getSize(); i++) {
        cout << fmt::format("\t{}:\n\t\tcenter: {}, area: {} ", vec[i]->name(), vec[i]->getCenter(), round(vec[i]->getArea()*100)/100) << *vec[i] << endl;
    }
    cout << "Enter the index for removal, use natural system (0th element is 1): " << endl;
    int removalIndex;
    cin >> removalIndex;
    vec.remove(removalIndex - 1);
    cout << fmt::format("The array with {} element removed:", removalIndex) << endl; 
    double totalArea = 0;
    for (int i = 0; i < vec.getSize(); i++) {
        totalArea += (double) *vec[i];
        cout << fmt::format("\t{}:\n\t\tcenter: {}, area: {} ", vec[i]->name(), vec[i]->getCenter(), round(vec[i]->getArea()*100)/100) << *vec[i] << endl;
    }

    cout << "Total area: " << totalArea << endl;

    return 0;
}
