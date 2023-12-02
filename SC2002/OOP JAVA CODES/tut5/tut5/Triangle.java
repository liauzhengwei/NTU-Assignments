package tut5;

public class Triangle extends Polygon{
    public Triangle(String theName, float theWidth, float theHeight){
        super(theName, theWidth, theHeight);
        super.setPolytype(KindOfPolygon.POLY_TRIANG);
    }

    public float calArea(){
        return 0.5f * super.height * super.width;
    }

}
