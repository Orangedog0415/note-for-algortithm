package Java.Demo;

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("小明", 20);
        Student s2 = new Student("小红", 19);

        System.out.println(s1.name);

        s1.study();
        s2.introduce();
    }
}