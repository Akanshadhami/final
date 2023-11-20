import java.util.*;

public class optimal{

    public static boolean search(int key,ArrayList<Integer>fr){
        for(int i=0;i<fr.size();i++){
            if(key==fr.get(i)){
                return true;

            }
        }
        return false;
    }

    public static int predict(int pg[],ArrayList<Integer>fr,int pn,int index){
        int res=-1;
        int farthest=index;
        for(int i=0;i<fr.size();i++){
            int j;
            for(j=index;j<pn;j++){
                if(pg[j]==fr.get(i)){
                    if(j>farthest){
                        farthest=j;
                        res=i;
                        break;
                    }
                }

            }
            if(j==pn)
            return i;
        }

        if(res==-1)
        {
            return 0;
        }
        else{
            return res;
        }
    }

    public static void optimalpage(int pg[],int pn,int fn){
        ArrayList<Integer>fr=new ArrayList<>();
        
        int pagehit=0;
        for(int i=0;i<pn;i++){
            if(search(pg[i],fr)){
                pagehit++;
                continue;

            }

            if(fr.size()<fn){
                fr.add(pg[i]);
            }
            else{
                int j=predict(pg,fr,pn,i+1);
                fr.set(j,pg[i]);
            }
            for(Integer it:fr){
            System.out.print(it+" ");
        }
        System.out.println();

           

        }
        
         int pagefault=pn - pagehit;
            System.out.println("pagehit:"+pagehit);
            System.out.println("pagefault:"+pagefault);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the value of pages: ");
        int pn = scanner.nextInt();
        int[] pg = new int[pn];

        System.out.println("Enter the page numbers:");
        for (int i = 0; i < pn; i++) {
            pg[i] = scanner.nextInt();
        }

        System.out.print("Enter the number of frames: ");
        int fn = scanner.nextInt();

        optimalpage(pg, pn, fn);
    }
}