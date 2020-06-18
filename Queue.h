#ifndef QUEUE_H
#define QUEUE_H
#include <QDebug>


template<typename T>
class Queue {
    int counter = 0;
    int m_size;
    bool typequalifier = true;
        T *array;
public:

    Queue (int size, bool par) {
        if (par == true) {
            MakerInt(size);
            typequalifier = true;
        } else {
            MakerStr(size);
            typequalifier = false;
        }
    }

    void MakerInt (int size) {
        array = new T[size];
        m_size = size;
       /* for(int i=0; i < (m_size-1); i++) {
            array[i]=0;
        } */
    }

    void MakerStr (int size) {
        array = new T[size];
   /*     m_size = size;
        for(int i=0; i < (m_size-1); i++) {
            array[i]='0';*/
    }

    Queue (int size) {   //old variant
        array = new T[size];
        m_size = size;
    }

    void enqueue(T value) {

        array[counter] = value;
        counter++;
        if (counter == m_size) {
            Expansion();
        }


    }


 /*   T dequeueint() {
        T enq = array[0];
        if (counter != 0) {
        for (int i = 0; i < (counter-1); i++ ) {
            array[i]=array[i+1];
        }
        if (counter == 0) {

        } else {
        counter--;
        return  enq;
        }
        }
        else {
            return 0;
        }
    }

    T dequeuestr() {
        if (counter==0) {
            return "Please enter new element";
        } else{
        T enq = array[0];
        for (int i = 0; i < (counter-1); i++ ) {
            array[i]=array[i+1];
        }

        counter--;
        return  enq;
        }
    } */

   T dequeue () {
        T enq = array[0];
        for (int i = 0; i < (counter-1); i++ ) {
            array[i]=array[i+1];
        }
        counter--;
        return  enq;
    }

    int getSize() {
        return counter;
    }

    T top () {
        return array[0];
    }

    void Deletion() {
        if ((counter+1) < (m_size/2)) {
            T *array2 = new T[counter+1];
            for (int i =0; i <= counter; i ++){
                array2[i] = array[i];
            }
            T *array = new T[counter+1];
            for(int i =0; i <=counter; i++) {
                array[i] = array2[i];
            }
            delete [] array2;
        }
    }

    void Expansion(){
        T *array2 = new T[counter*2];
        for (int i =0; i < counter; i ++){
            array2[i] = array[i];
        }
        m_size = m_size*2;
        T *array = new T[m_size];
        for(int i =0; i< counter; i++){
            array[i]=array2[i];
        }
        delete [] array2;
    }

    void print() {
        for (int i =0; i <counter; i++){
        qDebug()<<array[i];
        }
    }



};

#endif // QUEUE_H
