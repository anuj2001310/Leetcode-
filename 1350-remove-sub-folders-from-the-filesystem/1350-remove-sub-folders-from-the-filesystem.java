class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);

        List<String> list = new ArrayList<>();

        list.add(folder[0]);
        for (int i = 1; i < folder.length; i++) {
            String lastFolder = list.get(list.size() - 1);
            if (!folder[i].startsWith(lastFolder + "/")) {
                list.add(folder[i]);
            }
        }
        return list;
    }
}