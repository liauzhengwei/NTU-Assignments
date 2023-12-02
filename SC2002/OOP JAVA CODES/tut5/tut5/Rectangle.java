package tut5;

public class Rectangle extends Polygon{

    public Rectangle(String theName, float theWidth, float theHeight){
        super(theName, theWidth, theHeight);
        super.setPolytype(KindOfPolygon.POLY_RECT);
    }
    
    public float calArea(){
        return super.height* super.width;
    }
}
