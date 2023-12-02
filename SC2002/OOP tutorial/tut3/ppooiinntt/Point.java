package ppooiinntt;

public class Point{
    protected int x;
    protected int y;

    public Point(){
        x = 0;
        y = 0;
    }

    public Point(int x,int y){
        this.x = x;
        this.y = y;
    }

    public String toString(){
        return "[" + Integer.toString(x) +"," + Integer.toString(y) + "]";
    }
    //

    public void setPoint(int x,int y){
        this.x = x;
        this.y = y;
    }

    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }
}

