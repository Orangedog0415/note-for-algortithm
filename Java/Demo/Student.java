package Java.Demo;

public class Student {
    String name;
    int age;

    public Student(String inputName, int inputAge){
        name = inputName;
        age = inputAge;
    }

    public void study(){
        System.out.println(name + "is studying Java!");
    }

    public void introduce(){
        System.out.println("hello, i'm " + name + ".");
    }
}