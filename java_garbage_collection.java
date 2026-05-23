// Java: Memory Management - Garbage Collection Demo

public class MemoryDemo {
    
    // Inner class to represent a memory object
    static class MemoryBlock {
        String name;
        int[] data;
        
        MemoryBlock(String name, int size) {
            this.name = name;
            this.data = new int[size];
            System.out.println("ALLOCATED: " + name + 
                             " (" + size + " integers)");
        }
        
        // Called by GC before object is collected
        @Override
        protected void finalize() {
            System.out.println("GC COLLECTED: " + name);
        }
    }
    
    public static void main(String[] args) {
        System.out.println("=== JAVA GARBAGE COLLECTION DEMO ===\n");
        
        System.out.println("--- Allocating objects ---");
        
        // Allocate objects on the heap using 'new'
        MemoryBlock block1 = new MemoryBlock("Block-1", 100);
        MemoryBlock block2 = new MemoryBlock("Block-2", 200);
        MemoryBlock block3 = new MemoryBlock("Block-3", 300);
        
        System.out.println("\nAll blocks allocated and in use.");
        System.out.println("block1 points to: " + block1.name);
        System.out.println("block2 points to: " + block2.name);
        System.out.println("block3 points to: " + block3.name);
        
        System.out.println("\n--- Removing references ---");
        
        // Remove references — objects become eligible for GC
        // Developer does NOT manually free memory
        block1 = null;
        block2 = null;
        System.out.println("block1 reference set to null");
        System.out.println("block2 reference set to null");
        System.out.println("Block-1 and Block-2 are now GC eligible");
        System.out.println("block3 still referenced: " + block3.name);
        
        System.out.println("\n--- Requesting Garbage Collection ---");
        
        // Request GC — not guaranteed to run immediately
        System.gc();
        
        // Small pause to allow GC to run
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("\n--- Scope-based cleanup demo ---");
        
        // Object created in inner scope
        {
            MemoryBlock tempBlock = new MemoryBlock("TempBlock", 50);
            System.out.println("TempBlock in use: " + tempBlock.name);
        }
        // tempBlock reference gone — eligible for GC now
        System.out.println("TempBlock reference out of scope");
        
        System.gc();
        try { Thread.sleep(100); } catch (InterruptedException e) {}
        
        System.out.println("\n--- Program ending ---");
        System.out.println("block3 still alive: " + block3.name);
        System.out.println("Java GC handles all cleanup automatically");
        System.out.println("Developer never calls free() or delete");
    }
}