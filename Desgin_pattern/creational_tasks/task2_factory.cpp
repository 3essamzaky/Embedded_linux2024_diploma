#include <iostream>
#include <memory>

class editor{
public:
    virtual void render() const = 0;
    virtual ~editor() = default;    
};

class PDF : public editor{
public:
    void render() const override{
        std::cout << "PDF" << std::endl;

    }

};

class Word : public editor{
public:
    void render() const override{
        std::cout << "Word" << std::endl;
    }

};



class Factory{

public:
    virtual std::unique_ptr<editor> create_editor() const = 0;
    void render(){
        auto editor = create_editor();
        editor->render();
    }


    virtual ~Factory() = default;
};

class PDF_factory : public Factory{
public:
    std::unique_ptr<editor> create_editor() const override{
        return std::make_unique<PDF>();
    }
};

class Word_factory : public Factory{
public:
    std::unique_ptr<editor> create_editor() const override{
        return std::make_unique<Word>();
    }
};


int main(){
    std::unique_ptr<Factory> factory = std::make_unique<PDF_factory>();
    factory->render();

    factory = std::make_unique<Word_factory>();
    factory->render();

    return 0;
}