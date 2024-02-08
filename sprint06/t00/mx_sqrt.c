int mx_sqrt(int x) {

    if (x <= 0) {
        return 0;
    } else {
        int low = 1;
        int high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int result = high;
        if (result * result == x) {

            return result;
        } else {

            return 0;
        }
    }
}
