#include "Evaluador.h"



void evaluar()
{
    float nota = 0;

    escribirNumeroTexto("test_a", 10);
    escribirNumeroTexto("test_b", 20);
    escribirNumeroTexto("test_c", 30);
    ofstream o1("test_d");
    o1<<40;
    o1.close();

    cout<<"escribir y leerNumeroTexto:\t";
    if(leerNumeroTexto("test_a")==10 && leerNumeroTexto("test_b")==20 && leerNumeroTexto("test_c")==30 && leerNumeroTexto("test_d")==40)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    escribirStringTexto("test_a", "asd");
    escribirStringTexto("test_b", "qwe");
    escribirStringTexto("test_c", "zxc");
    ofstream o2("test_d");
    o2<<"qwerty";
    o2.close();

    cout<<"escribir y leerStringTexto:\t";
    if(leerStringTexto("test_a")=="asd" && leerStringTexto("test_b")=="qwe" && leerStringTexto("test_c")=="zxc" && leerStringTexto("test_d")=="qwerty")
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    escribirNumeroBinario("test_a", 10);
    escribirNumeroBinario("test_b", 20);
    escribirNumeroBinario("test_c", 30);
    ofstream o3("test_d");
    int o1n=40;
    o3.write((char*)&o1n,4);
    o3.close();

    cout<<"escribir y leerNumeroBinario:\t";
    if(leerNumeroBinario("test_a")==10 && leerNumeroBinario("test_b")==20 && leerNumeroBinario("test_c")==30 && leerNumeroBinario("test_d")==40)
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    escribirStringBinario("test_a", "abc");
    escribirStringBinario("test_b", "de");
    escribirStringBinario("test_c", "fghi");
    ofstream o4("test_d");
    string o1s="oriq";
    o4.write(o1s.c_str(),10);
    o4.close();

    cout<<"escribir y leerStringBinario:\t";
    if(leerStringBinario("test_a")=="abc" && leerStringBinario("test_b")=="de" && leerStringBinario("test_c")=="fghi" && leerStringBinario("test_d")=="oriq")
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    ofstream o5("test_e");
    o5<<"hola mundo chuck testa shrek is life";
    o5.close();

    ofstream o6("test_f");
    o6<<"how to basics rtil amor comprension y ternura";
    o6.close();

    cout<<"existe:\t\t\t\t";
    if(existe("test_e","hola") && existe("test_e","is") && existe("test_e","life") && !existe("test_e","amor") && !existe("test_e","ternura") && !existe("test_e","gohan")
        && existe("test_f","amor") && existe("test_f","basics") && existe("test_f","ternura") && !existe("test_f","lola") && !existe("test_f","life") && !existe("test_f","tribilin"))
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    int a=10,b=20,c=30,d=40,e=50,f=60,g=70;
    ofstream o7("test_g");
    o7.write((char*)&d,4);
    o7.write((char*)&b,4);
    o7.write((char*)&a,4);
    o7.write((char*)&g,4);
    o7.close();

    ofstream o8("test_h");
    o8.write((char*)&e,4);
    o8.write((char*)&f,4);
    o8.write((char*)&a,4);
    o8.write((char*)&b,4);
    o8.close();

    cout<<"obtenerMayor:\t\t\t";
    if(obtenerMayor("test_g")==70 && obtenerMayor("test_h")==60)
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/13"<<endl;
}
