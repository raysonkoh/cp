package dir;

public class Cat {
    private final String name;
    public Cat(String name) {
        this.name = name;
    }
    public void meow() {
        System.out.println(name + " goes meow meow");
    }
}