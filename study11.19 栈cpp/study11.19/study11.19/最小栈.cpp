//public class MinStack {
//	public static void main(String[] args) {
//		MinStack minStack = new MinStack();
//		minStack.push(-2);
//		minStack.push(0);
//		minStack.push(-3);
//		System.out.println("min: " + minStack.getMin());
//		minStack.pop();
//		System.out.println("top: " + minStack.top());
//		System.out.println("min: " + minStack.getMin());
//	}
//
//	private int mNum;
//	private int mMin;
//	private int mMinIndex;
//	private List<Integer> list;
//	private List<Integer> mMinIndexs;
//
//	public MinStack() {
//		list = new ArrayList<>();
//		mMinIndexs = new ArrayList<>();
//	}
//
//	public void push(int x) {
//		mNum++;
//		list.add(x);
//		if (mNum == 1) {
//			mMin = x;
//			mMinIndex = 0;
//		}
//		else {
//			if (x > mMin) {
//			}
//			else {
//				mMin = x;
//				mMinIndex = mNum - 1;
//			}
//		}
//		mMinIndexs.add(mMinIndex);
//	}
//
//	public void pop() {
//		if (mNum > 0) {
//			list.remove(mNum - 1);
//			mMinIndexs.remove(mNum - 1);
//			mNum--;
//			if (mNum > 0) {
//				mMinIndex = mMinIndexs.get(mNum - 1);
//				mMin = list.get(mMinIndexs.get(mMinIndex));
//			}
//			else {
//				mMin = 0;
//				mMinIndex = 0;
//			}
//		}
//	}
//
//	public int top() {
//		if (mNum > 0) {
//			return list.get(mNum - 1);
//		}
//		return Integer.MIN_VALUE;
//	}
//
//	public int getMin() {
//		if (mNum > 0) {
//			return list.get(mMinIndexs.get(mNum - 1));
//		}
//		return Integer.MIN_VALUE;
//	}
//}