public interface DBMethods{
    public <T> void insert(T newString);
    public void update(String query);
    public void delete(String query);
}