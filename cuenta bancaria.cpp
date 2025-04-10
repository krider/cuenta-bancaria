#include <iostream>
#include <vector>

class Cuenta {
private:
    int numero;
    double saldo;

public:
 
    Cuenta(int num, double sal) : numero(num), saldo(sal) {}
    
    int getNumero() const { return numero; }
   
    double getSaldo() const { return saldo; }
    
    void depositar(double monto) { saldo += monto; }
    
    bool retirar(double monto) {
        if (monto <= saldo) {
            saldo -= monto;
            return true;
        }
        return false;
    }
};

int main() {
    std::vector<Cuenta> cuentas;
    int opcion;
    double monto;
    
    cuentas.push_back(Cuenta(123, 0.0));
    
    std::cout << "Bienvenido\n";
    
    int num_cuenta;
    std::cout << "Ingrese el numero de cuenta: ";
    std::cin >> num_cuenta;
    
    auto it = std::find_if(cuentas.begin(), cuentas.end(), 
        [num_cuenta](const Cuenta& c) { return c.getNumero() == num_cuenta; });
    
    if (it == cuentas.end()) {
        std::cout << "Cuenta no encontrada\n";
        return 1;
    }
    
    Cuenta& cuenta_actual = *it;

    do {
        std::cout << "\nMenu de operaciones:\n";
        std::cout << "1. Depositar\n";
        std::cout << "2. Retirar\n";
        std::cout << "3. Consultar saldo\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                std::cout << "Ingrese monto a depositar: ";
                std::cin >> monto;
                cuenta_actual.depositar(monto);
                std::cout << "Deposito exitoso. Saldo actual: " 
                          << cuenta_actual.getSaldo() << "\n";
                break;
                
            case 2:
                std::cout << "Ingrese monto a retirar: ";
                std::cin >> monto;
                if (!cuenta_actual.retirar(monto)) { 
                    std::cout << "Saldo insuficiente\n";
                } else {
                    std::cout << "Retiro exitoso. Saldo actual: " 
                              << cuenta_actual.getSaldo() << "\n";
                }
                break;
                
            case 3:
                std::cout << "Saldo actual: " 
                          << cuenta_actual.getSaldo() << "\n";
                break;
                
            case 4:
                std::cout << "Hasta Luego\n";
                break;
                
            default:
                std::cout << "Opcion invalida\n";
        }
    } while(opcion != 4);

    return 0;
}
