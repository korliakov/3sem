#include <iostream>
#include <vector>
#include <string>

// Electromagnetic interaction
// You have to create world and be able to add and delete particles from it
// When you add or delete particle you must recalculate all interactions

// Требуется описать мир с некоторыми частицами
// Координата/скорость задается через структуру vector3

struct vector3 {
    double x;
    double y;
    double z;
};

// Для описания событий происходящих в мире напишите свой небольшой логгер, который умеет
// Запоминать создание, изменение и уничтожение частиц

class Logger {
public:
    Logger() = default;
    void log(const std::string& s) {
        
        l.push_back(s);

    }


    //доступ к значению l
    
    std::vector<std::string> get_status() {
        return l;
    }   
    ~Logger() = default;
private:
    std::vector<std::string> l;
};

// Существует базовый класс частиц, который внутри себя хранит информацию о частице
// Допишите этот родительский класс так, чтобы он мог считать количество объектов, созданных от него    готово

class Particle {

private:
    static int counter;

protected:
    // Поля, описывающие частицу
    // Можно дописать свои
    double mass = 0;
    double charge = 0;
    vector3 coordinate = {0, 0, 0};
    vector3 velocity = {0, 0,0};
    vector3 force = {0, 0, 0};
    std::string name;
    // Логгер для записи событий
    Logger logger;

public:

    Particle() {}
    explicit Particle(double energy) {}

    // метод, который вам необходимо переопределить в дочерних классах
    // см. или вспомнить лекцию
    // внутри него напишите логику взаимодействия двух частиц (например, кулоновское)
    //virtual void interaction(Particle& p);
    std::string getName() const;
    std::string getEnergy() const;
    //подсчет частиц
    static int GetCounter() {return counter;}
};


int Particle::counter = 0;

// описать несколько классов разных частиц
// например такой
class Electron : public Particle {
public:
    Electron() {
        std::string str = "created";
        logger.log(str);
        //std::cout << logger.get_status()[0] << std::endl;
 
    };
    // в этом конструкторе предлагается задавать координаты и через энергию остальные параметры частицы
    explicit Electron(double energy, vector3 coords) {
        std::string str = "created";
        logger.log(str);
        //принт для проверки работы логгера
        //std::cout << logger.get_status()[0] << std::endl;
 
    };
    //void interaction(Particle& p) override;
    ~Electron()  {
        std::string str = "deleted";
        logger.log(str);
        //std::cout << logger.get_status()[0] << std::endl;
 
    };
};

// в этом классе опишите мир, состоящий из некоторого числа частиц
class World {
    std::vector<Particle> v;
public:
    // добавить частицу в мир (она должна провзаимодействовать со всеми остальными)
    void addParticle(const Particle& p) {
        std::cout << "частиц всего: " << Particle::GetCounter() << std::endl;
       // v.push_back(p);
        std::cout << "частиц всего: " << Particle::GetCounter() << std::endl;
    };
    // удалить частицу из мира
    void deleteParticle(const Particle& p) {
         
    };
};

// перегрузите оператор вывода, чтобы можно было вывести состав мира
// (может потребоваться перегрузка оператора вывода для частиц)
std::ostream& operator<<(std::ostream& os, const World& w);

// здесь создайте мир/миры, куда добавьте некоторое число частиц, взаимодействующих друг с другом
int main() {
    
    World world; 
    
    Particle p(2.0);    
    Electron e;
    // world.addParticle(p);
}
