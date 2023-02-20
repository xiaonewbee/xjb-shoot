// 作者：梨梨喵
// 链接：https://www.zhihu.com/question/38097768/answer/74893669
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Any
{
public:
  template <class T>
  using StorageType = typename std::decay<T>::type;

  template <typename U,
            class = typename std::enable_if<
                !std::is_same<StorageType<U>, Any>::value, void>::type>
  Any(U &&_value)
      : ptr(new Container<StorageType<U>>(std::forward<U>(_value)))
  {
  }

  Any()
      : ptr(nullptr)
  {
  }

  Any(const Any &_that)
      : ptr(_that.clone())
  {
  }

  Any(Any &&_that)
      : ptr(_that.ptr)
  {
    _that.ptr = nullptr;
  }

  template <class U>
  inline bool is() const
  {
    typedef StorageType<U> T;

    if (!ptr)
      return false;

    auto derived = dynamic_cast<Container<T> *>(ptr);

    return !(derived == nullptr);
  }

  template <class U>
  inline StorageType<U> &as() const
  {
    typedef StorageType<U> T;

    if (!ptr)
      throw std::bad_cast();

    auto container = dynamic_cast<Container<T> *>(ptr);

    if (!container)
      throw std::bad_cast();

    return container->value;
  }

  template <class U>
  inline StorageType<U> &value() const
  {
    return as<StorageType<U>>();
  }

  template <class U>
  inline
  operator U() const
  {
    return as<StorageType<U>>();
  }

  Any &operator=(const Any &a)
  {
    if (ptr == a.ptr)
      return *this;
    auto old_ptr = ptr;
    ptr = a.clone();
    if (old_ptr)
      delete old_ptr;
    return *this;
  }

  Any &operator=(Any &&a)
  {
    if (ptr == a.ptr)
      return *this;
    std::swap(ptr, a.ptr);
    return *this;
  }

  ~Any()
  {
    if (ptr)
      delete ptr;
  }

private:
  class ContainerBase
  {
  public:
    virtual ~ContainerBase() {}
    virtual ContainerBase *clone() const = 0;
  };

  template <typename T>
  class Container
      : public ContainerBase
  {
  public:
    template <typename U>
    Container(U &&value)
        : value(std::forward<U>(value))
    {
    }

    inline ContainerBase *clone() const
    {
      return new Container<T>(value);
    }

    T value;
  };

  inline ContainerBase *clone() const
  {
    if (ptr)
      return ptr->clone();
    else
      return nullptr;
  }

  ContainerBase *ptr;
};
