package Java.Demo;

class Animal {
    void eat() {
        System.out.println("动物吃东西");
    }
}

class Dog extends Animal {
    @Override
    void eat() {
        System.out.println("狗吃骨头"); // 重写
    }
    
    void lookAfterHouse() {
        System.out.println("狗看家");
    }
}

class Cat extends Animal {
    @Override
    void eat() {
        System.out.println("猫吃鱼");   // 重写
    }
}

public class polymorphism {
    public static void main(String[] args) {
        // 【关键点】：父类引用 = 新建子类对象
        Animal a1 = new Dog(); 
        Animal a2 = new Cat();

        // 这里的 .eat() 到底调用的谁？
        a1.eat(); // 输出：狗吃骨头
        a2.eat(); // 输出：猫吃鱼
        
        // a1.lookAfterHouse(); // 报错！！为什么？下面讲
    }
}