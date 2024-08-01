#include <QCoreApplication>
#include <QDebug>

class Cachorro {
public:
    Cachorro( const QString& raca ) :
        _raca(raca){}

    QString getRaca() const {
        return _raca;
    }

private:
    QString _raca;
};

class Petshop {
public:
    void atender() { return; }
    virtual QString especialidade() const {
        return "GERAL";
    }
};

class PetshopDalmata : public Petshop {
public:
    virtual QString especialidade() const override {
        return "DALMATAS";
    }
};

class PetshopGoldenRetriever : public Petshop {
public:
    virtual QString especialidade() const override {
        return "GOLDEN RETRIEVERS";
    }
};

class PetshopFactory {
public:
    //de acordo com a raça do cachorro essa classe vai criar um petshop especifico
    Petshop* criar( const QString& racaDoCachorro ) {
        //o ideal nesse caso é usar um switch ao invés do if, aqui usamos if para ficar mais simples

        //se a raça for DALMATA, retorna um petshop especializado em DALMATAS
        if ( racaDoCachorro == "DALMATA" ) {
            return new PetshopDalmata();

        //se a raça for GOLDEN RETRIEVER, retorna um petshop especializado em GOLDEN RETRIEVER
        } else if (racaDoCachorro == "GOLDEN RETRIEVER" ) {
            return new PetshopGoldenRetriever();
        }

        //caso não seja especificada uma raça, vai retornar um petshop geral
        return new Petshop();
    }

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //criando meu objeto Cachorro, da raça Dalmata
    Cachorro* myDog = new Cachorro("DALMATA");

    //criando um objeto do tipo Petshop de acordo com a necessidade da raça do meu cachorro
    Petshop* petshopEspecializado = ( new PetshopFactory() )->criar( myDog->getRaca() );

    //verificando se o petshop foi criado corretamente
    //deve ter como saida o texto "DALMATAS"
    qDebug() << petshopEspecializado->especialidade();

    delete petshopEspecializado;

    return a.exec();
}
