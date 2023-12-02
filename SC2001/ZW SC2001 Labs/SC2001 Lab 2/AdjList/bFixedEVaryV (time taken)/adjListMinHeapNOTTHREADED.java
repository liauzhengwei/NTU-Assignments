import java.io.*;
import java.lang.*;
import java.util.*;

import com.opencsv.CSVWriter;

public class adjListMinHeapNOTTHREADED {
	
	static int keyComparisons;
    static long totalTime;
	
	static class Node{
		
		int vertex;
		int weight;
		
		Node(int v, int w){
			this.vertex = v;
			this.weight = w;
		}
	}
	
	int dijkstra(List<List<Node>> adjList, int src, int V) {
		
		int [] dist = new int [V];
		
		for(int i = 0; i < V; i++) {
			dist[i] = Integer.MAX_VALUE;
		}
		dist[src] = 0;

		List<Node> minHeap = new ArrayList<Node>();

		minHeap.add(0,new Node(src, 0));

        //Updatedqy we create the S array to mark which nodes are already in the confirmed set
        int[] S=new int[V];
        
        for(int i=0;i<V;i++)
        {
            S[i]=0;
        }

        
		while (!minHeap.isEmpty()) {
        	
			//extract min dist from minHeap
            Node u = deleteMin(minHeap); 
            int uVertex = u.vertex;
            
            //Updatedqy We ignore that node if it was already added to the confirmed set.
            if(S[uVertex]==1)continue;
            //Updatedqy else set the popped vertex to be part of confirmed set, then explore neighbours.
            else S[uVertex]=1;
            
            //explore neighbour, update distance if shorter path found
            
            //Updatedqy this part will only be reached a max V number of times because of the previous check. (j writing here for my own note for time complexity calculations)
            for (Node neighbour : adjList.get(uVertex)) {
            	
                int v = neighbour.vertex;
                int UV = neighbour.weight;
                
                if (dist[uVertex] != Integer.MAX_VALUE && dist[uVertex] + UV < dist[v] && S[v]!=1) {  //Updatedqy Added && S[V]!=1 so we dont check any vertices that are alr in the confirmed set.
                    dist[v] = dist[uVertex] + UV;
                    minHeap.add(new Node(v, dist[v]));
                    fixHeap(minHeap);
                }
                //Updatedqy for time complexity, moved this out of the for loop coz key comps will happen as long as if() is checked.
                adjListMinHeapNOTTHREADED.keyComparisons++;
            }
            
        }

        //printSolution(dist, V); UpdatedQy commented printSolution out coz i j want the code to be faster LOL.
        return adjListMinHeapNOTTHREADED.keyComparisons;
    }
	
	Node deleteMin(List<Node> minHeap) {
		
		//copy rightmost element at lowest level to top
		int last = minHeap.size()-1;
		Node minNode = minHeap.get(0);
		minHeap.set(0, minHeap.get(last));
		minHeap.remove(last);
		
		fixHeap(minHeap);
		
		return minNode;
	}
	
	void fixHeap(List<Node> minHeap) {
		
		int index = 0;
		int size = minHeap.size();

		while(true) {
			
			int leftChild = 2*index+1;
			int rightChild = 2*index+2;
			int smallest = index; //assume current node smallest initially
			
			
			if (leftChild < size && minHeap.get(leftChild).weight < minHeap.get(smallest).weight) {
				keyComparisons++;
                smallest = leftChild;
            }

            if (rightChild < size && minHeap.get(rightChild).weight < minHeap.get(smallest).weight) {
            	keyComparisons++;
                smallest = rightChild;
            }

            //check if child node contains smaller value than current node
            if (smallest != index) {
                swap(minHeap, index, smallest);
                index = smallest;
            } else {
                break;
            }
		}
	}
	
	
	void swap(List<Node> minHeap, int i, int j) {
		
        Node temp = minHeap.get(i);
        minHeap.set(i, minHeap.get(j));
        minHeap.set(j, temp);
    }
	
	void printSolution(int[] dist, int V) {
        System.out.println("Vertex \t\t Distance from Source");
        for (int i = 0; i < V; i++) {
            if (dist[i] != Integer.MAX_VALUE) {
                System.out.println(i + " \t\t " + dist[i]);
            } else {
                System.out.println(i + " \t\t Null");
            }
        }
    }

    public List<List<Node>> generateInput(int n, int E) {
    	
    	int edges = 0;
    	
        Random rand = new Random();
        List <List<Node>> adjList = new ArrayList<List<Node>>();

        //updatedqy Initialise list objects within the biglist
        for(int i=0;i<n;++i)
        {
            adjList.add(new ArrayList<Node>());
        }

        /*for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>()); 
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int a = rand.nextInt(4);
                    if (a == 1) {
                        int weight = rand.nextInt(100);
                        adjList.get(i).add(new Node(j, weight));
                    }
                }
            }
        }*/

        //updatedQy if we want connected graph, but we arnt doing it so j ignore this.
        /* 
        final int CONNECTED_NODE=1;
        for(int i=0;i<n;++i)
        {
            int randomWeight=rand.nextInt(100);
            adjList.get(CONNECTED_NODE).add(new Node(i,rand.nextInt(100)));
            adjList.get(i).add(new Node(CONNECTED_NODE,randomWeight));
            edges++;
        }
        */

        
        while(edges < E) {
        	int u = rand.nextInt(n);
        	int v = rand.nextInt(n);
            //updatedqy so it doesnt can avoid potentially placing multiple edges to one vertex in a list.
        	if(u!=v) 
            {
                int exists=0;
                for(int i=0;i<adjList.get(u).size();++i)
                {
                    if((adjList.get(u)).get(i).vertex==v)exists=1;//Vertex already exists in that node.
                }

                if(exists==1)continue;
                else //else we add both directions to nodes.
                {
                    int weight = rand.nextInt(100);
                    adjList.get(u).add(new Node(v, weight));
                    edges++;
                }
        		
        	}
        }
        
        
        return adjList;
    }
    
    /*public static void main(String[] args) {
        int V = 100;
        
        adjListMinHeap t = new adjListMinHeap(); 
        List<List<Node>> adjList = t.generateInput(V);

        t.dijkstra(adjList, 0, V);
        System.out.println("Key Comparisons: " + keyComparisons);
        
    }*/
    
    public static void main(String[] args) {
        try {
            File file = new File("VaryingVertices.csv");
            FileWriter outputfile = new FileWriter(file);
            CSVWriter writer = new CSVWriter(outputfile);

            String[] header = { "Number of Vertices", "Number of edges", "Average Key Comparisons" };
            writer.writeNext(header);

            adjListMinHeapNOTTHREADED t = new adjListMinHeapNOTTHREADED();
            final int NUMBER_OF_ITERATIONS = 100;

    
 
            //fixed E, varying V
            for (int V = 10; V <= 1000; V ++) {
            	
            	int E =(int) (((float)3/(float)8)*(V*V-V)); //fixed E
                int totalComparisons = 0;
                long totalTime=0;

                for (int i = 0; i < NUMBER_OF_ITERATIONS; i++) {
                    //Updatedqy need to reset key comps for every run of djisktra, or they would just keep stacking.
                    adjListMinHeapNOTTHREADED.keyComparisons=0;
                    List<List<Node>> adjList = t.generateInput(V, E);
                    long start=System.nanoTime();
                    t.dijkstra(adjList, 0, V);
                    long end=System.nanoTime();
                    long taken=end-start;
                    totalTime += taken;
                }

                double avgTime = (double) totalTime / NUMBER_OF_ITERATIONS;
                String[] result = {"Varying V, Fixed E", Integer.toString(V), Double.toString(avgTime) };
                writer.writeNext(result);

                System.out.printf("For Number of Vertices of %d, Fixed Edges of %d, average of %f key comparisons written to CSV.\n", V,
                        E, avgTime);
            }


            
            /* 
            //fixed V, varying E
            for (int E = 100; E <= 9900; E += 98) {
            	
            	int V = 100;
                long totalComparisons = 0;

                for (int i = 0; i < NUMBER_OF_ITERATIONS; i++) {
                	//Updatedqy need to reset key comps for every run of djisktra, or they would just keep stacking.
                    adjListMinHeap.keyComparisons=0;
                    List<List<Node>> adjList = t.generateInput(V, E);
                    int comparisons = t.dijkstra(adjList, 0, V);
                    totalComparisons += comparisons;
                }

                double avgComparisons = (double) totalComparisons / NUMBER_OF_ITERATIONS;
                String[] result = { "Varying E, Fixed V", Integer.toString(E), Integer.toString(V), Double.toString(avgComparisons) };
                writer.writeNext(result);

                System.out.printf("For Number of Edges of %d, Fixed V of %d, average of %f key comparisons written to CSV.\n", E,
                        V, avgComparisons);
            }
            */
    

            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
