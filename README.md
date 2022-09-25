# grafoCPP
minha implementação de grafos em c++ para a matéria de estrutura de dados 2 

## Build

para compilar o projeto você pode rodar o script build.sh:

```sh
chmod u+x build.sh
./build.sh
```

alternativamente, você pode executar a sequência de comandos do script manualmente:

```sh
# apagando arquivos de build se existirem
rm -rf build 
rm -rf a.out
# criando diretório build e entrando nele
mkdir -p build
cd build
# gerando um Makefile a partir do arquivo do CMake na raiz do projeto 
cmake ..
# compilando o projeto
make 
# fazendo um link simbólico do executável na raiz do projeto (opcional)
ln -sr a.out ..
```

em ambos os casos será criado um arquivo a.out na raiz do projeto, de onde é possível rodar normalmente

```sh
./a.out
```