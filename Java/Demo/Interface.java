package Java.Demo;

// 1. 接口：定义一种能力
interface MagicUser {
    void castSpell(); // 施法
}

// 2. 抽象类：定义家族共性和状态
abstract class Character {
    protected String name;
    
    public Character(String name) {
        this.name = name;
    }
    
    public void move() {
        System.out.println(name + " 正在移动");
    }
    
    // 抽象攻击方法，战士是用剑，法师是用杖
    public abstract void attack(); 
}

// 3. 具体类：战士 (只是个角色，不会魔法)
class Warrior extends Character {
    public Warrior(String name) { super(name); }
    
    @Override
    public void attack() {
        System.out.println(name + " 挥舞大剑攻击！");
    }
}

// 4. 具体类：法师 (是角色，同时具备施法能力)
class Wizard extends Character implements MagicUser {
    public Wizard(String name) { super(name); }
    
    @Override
    public void attack() {
        System.out.println(name + " 发射火球！");
    }
    
    @Override
    public void castSpell() {
        System.out.println(name + " 正在念咒语...");
    }
}