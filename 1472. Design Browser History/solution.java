class BrowserHistory {
    private String[] history;
    private int historyIndex;
    private int currentIndex;

    public BrowserHistory(String homepage) {
        history = new String[101];
        history[0] = homepage;
        currentIndex = 0;
        historyIndex = 1;
    }
    
    public void visit(String url) {
        history[++currentIndex] = url;
        historyIndex = currentIndex + 1;
        // System.out.println("visit: " + url + " currentIndex: " + currentIndex + " historyIndex: " + historyIndex);
    }
    
    // ['a', 'b', 'c', null]
    //        ^     
    //.       |
    //.  currentIndex    historyIndex
    // currentIndex 1
    // historyIndex 3
    public String back(int steps) {
        if (steps > currentIndex) {
            currentIndex = 0;
            return history[currentIndex];
        }
        currentIndex -= steps;
        // System.out.println("currentIndex: " + currentIndex);
        return history[currentIndex];
    }
    
    public String forward(int steps) {
        if (historyIndex - currentIndex - 1 < steps) {
            currentIndex = historyIndex - 1;
            return history[currentIndex];
        }
        currentIndex += steps;
        return history[currentIndex];
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
