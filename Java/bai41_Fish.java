package Java;

public class bai41_Fish implements bai41_Prey,bai41_Predator {

    @Override
    public void hunt() {
        System.out.println("This fish is hunting smaller fish");
    }

    @Override
    public void flee() {
        System.out.println("This fish is fleeing from a larger fish");
    }
    
}
