#include <iostream>
#include <string>
#include <locale.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

//classe Produtos
class Produtos{
private:

    string nome;
    double preco;
    int estoque;
    string categoria;

public:
    //construtores
    Produtos() : nome(""), preco(0), estoque(0), categoria(""){}

    Produtos(string n, double p, int e) : nome(n), preco(p), estoque(e), categoria(""){}

    Produtos(string n, double p, int e, string c) : nome(n), preco(p), estoque(e), categoria(c){}

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
    string getCategoria() const{
        return categoria;
    }

    //setter para a categoria do produto
    void setCategoria(string c){
        categoria = c;
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
        cout << nome + ", " + to_string(estoque) + " em estoque, preço: " + to_string(preco) << endl;;
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

//método para listar todos produtos de uma categoria
void listar_produtos(vector<Produtos> lista, string categoria){
    vector<string> produtos;

    //loop com range-based percorrendo a listae salvando o nome dos produtos que pertencem à mesma categoria
    for (const Produtos& produto : lista){
        if(produto.getCategoria() == categoria){
            produtos.push_back(produto.getNome());
        }
    }

    for (int i = 0; i < produtos.size(); i++){
        cout << produtos[i] << " ";
    }
    cout << endl;
}

// método para calcular total
void calcTotal(vector<Produtos> lista){
    double total = 0;
    for (const Produtos& produto : lista){
        total += produto.getEstoque()*produto.getPreco();
    }
    cout << "valor total no inventário da loja: " << total << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    vector<Produtos> Loja;

    set<string> categorias;
    for (const Produtos& produto : Loja){
        categorias.insert(produto.getCategoria());
    }

    // quantidade de produtos por categoria
    map<string, int> contagem;
    { // percorrendo as categorias
        for (const string& categoria : categorias){
            int valor = 0;
            // percorrendo a lista de produtos para cada categoria e incrementando valor
            for (const Produtos& produto : Loja){
                if (produto.getCategoria() == categoria){
                    valor += valor * produto.getEstoque();
                }
            }
            contagem[categoria] = valor;
        }
        
    }

    // valor em estoque por categoria
    map<string, double> valor_estoque;
    {
        // percorrendo as categorias
        for (const string& categoria : categorias){
            double total = 0;
            //percorrendo os produtos para cada categoria 
            for (const Produtos& produto : Loja){
                //se o produto pertence a categoria soma o produto da quantidadem em estoque pelo preço no total
                if (produto.getCategoria()==categoria){
                    total += produto.getEstoque()*produto.getPreco(); 
                }
            }
            valor_estoque[categoria] = total;
        }
    }

    list<Produtos> historico;

    return 0;
}
