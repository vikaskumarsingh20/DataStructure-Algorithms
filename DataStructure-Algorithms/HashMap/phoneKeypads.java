class Solution {
    private ArrayList<String> master = new ArrayList<String>();

    public List<String> letterCombinations(String digits) {
        if (digits.equals("")) {
            return master;
        }
        
        HashMap<String, String> map = new HashMap<>();  // hashmap created
        map.put("2", "abc");
        map.put("3", "def");
        map.put("4", "ghi");
        map.put("5", "jkl");
        map.put("6", "mno");
        map.put("7", "pqrs");
        map.put("8", "tuv");
        map.put("9", "wxyz");

        combine("", digits, map);
        return master;
    }

    private void combine(String current, String remaining, HashMap<String, String> map) {
        if ("".equals(remaining)) {
            master.add(current);
            return;
        }
        String letters = map.get(remaining.substring(0,1));
        for (int i = 0; i < letters.length(); i++) {
            current += letters.substring(i, i + 1);
            combine(current, remaining.substring(1), map);
            current = current.substring(0, current.length() - 1);
        }
    }
}
