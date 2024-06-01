#include <iostream>

class Resource {
public:
    Resource() {
        // Захоплення ресурсу
        std::cout << "Ресурс захоплено" << std::endl;
    }

    void UseResource() {
        std::cout << "Ресурс використовується" << std::endl;
    }

    ~Resource() {
        // Звільнення ресурсу
        std::cout << "Ресурс звільнено" << std::endl;
    }
};

int main() {
    {
        Resource resource;
        resource.UseResource();
    } // Ресурс автоматично звільняється тут
    return 0;
}
