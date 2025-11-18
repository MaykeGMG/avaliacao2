#include <iostream>
#include <string>
#include <locale.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

class Produtos{
private:

    string nome;
    double preco;
    int estoque;

public:
    //construtores
    Produtos() : nome(""), preco(0), estoque(0){}

    Produtos(string n, double p, int e) : nome(n), preco(p), estoque(e){}

    //getters
    string getNome() const{
        return nome;
    }
    double getPreco() const{
        return preco;
    }
    int getEstoque() const{
        return estoque;
    }

    //operator <
    bool operator<(const Produtos& outroProduto){
        return nome < outroProduto.nome;
    }

    //operator ==
    bool operator==(const Produtos& outroProduto){
        return nome == outroProduto.nome;
    }

    void exibir() const{
        cout << nome + ", " + to_string(estoque) + " em estoque, preço: " + to_string(preco) + "\n" << endl;;
    }
};

//método para adicionar produto
void adicionar_produto(vector<Produtos>& lista, Produtos p1){
    lista.push_back(p1);
}

//método para buscar produto por nome
void buscar(const vector<Produtos>& lista, string nome){

    //loop por indice ao invés de range-based pra poder pegar o indice e usar o exibir()
    for (int i = 0; i < lista.size(); i++){
        string nameProd = lista[i].getNome();
        if(nameProd == nome){
            cout << nome << " está listado nos produtos." << endl;
            lista[i].exibir();
        }else{cout << nome << " não está na lista de produtos." << endl;}
    }
}



int main()
{
    setlocale(LC_ALL, "Portuguese");

    vector<Produtos> Loja;

    set<string> categorias;

    map<string, int> contagem;

    map<string, double> valor_estoque;

    list<Produtos> historico;

    return 0;
}
