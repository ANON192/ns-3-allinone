        /  	�      ���������l�`hػ�P׍�������            (�/�`�-! ��(��� R!��$|[j��v�"�ݽ�#��̠   ;0�� � � ��幵Jھ2�=}�Z�����ڪ�����Ǟݨ6��W�y�|��~�i�>�
���}mH�G�"W�HSRlr�ד���$��O���Қ�K���Id�H���23LN�LNd�c��fj���@{�Y�T��(d0�u�x.d8*� `ca��`]����*t Z͸S��x�3�H�,<��i#��B�������@�5q[��6���L	�U���Y�F�,y�V���K����L��L�,*B�[�$S��j��s�Q���Y��|�h��"���A�#_7���*���|)C�9���<��2e��:V��,���[�T{KKƊ��J3�(iVX�ZOfs�e��}:��̥g���أ�v&pQ2�
��6!����8�
���Ci\x(�Gj��`-ʓ�JʓWV�ä`���˫�[��&��W�d.��傱��Z�ևK,����ᛞ��0}�
��%��-�蒮����ߠu��G�$C���]�S��}�y�rKF�νR9�s��40�I��ٕ5B�!w�ՈLt��Z+�9	����4�}�]��|C�u�'�*ƟK�����L�S{G4�8��P[G������LS�e��;�>  �]җ��e�D����o��qz�u�|Z[���Io`��!�Ӹ5����!B
 � (A   �sV�31C��cT1a"� (�%�8E�]��3���V�H*��A��?��m����b��1���&��$0��M���35�gG9H�* M@��8*+�Y��k�hAaG�ԍ���&7�1���6sY��C�6�**+�D4�C��#F�؜��{l���@�{�>VV���G~5�t��`�]�3�����\i�QyCB*tB�,G�^�F��q�
+�Z`(��J'`i̩	����]%���z"#T�{���lW����1%b	OPS�B�l�P�>Mu.Qw��/ ��t�8a�VD�K���F�1�T��    /     �  	T      �    ������?�������1��b��N            (�/� � 
$)`� ���E���AvI�[c<٢��Q����Uyэ[��^�I�,�l���o�<�H�2̒u��O��0p*��0+��*�<��]���gh����|���Ω��uES������pR�yr��'*Je�/��8v� M���&�A�,e�T[`km��7��k-h    �     "  	R     �   �����_�i-4{aʲ�L��}���"              o  �   #include "ns3/ipv4.h"
    
     )  	Q     �   �����P���$�1�t��U��tQ=              �  �   class Ipv4Impl : public Ipv4
    3     7  	P     �   ����J��$��W��1u�bE���0G              ^  �   +  virtual Ipv4Route GetRoute (uint32_t i);
    j     [  	�     �   ����̌|z)SW�io�,5����            (�/� �� r���y��{W8Z���9��>� {�k���xmAt���Nnjz��%��b�|^�[��Q � 1 8g4%����e    �     0  	�     �   ������3���4�{�HU����            (�/� B=   x  �   6 int16_t priority);
 �    �     �  �     �   ����_�Y[E�"��C)l4�j51            (�/�` = �	!"�9������LBw�'?I�A�z���۾5J��r�2l��F@V$Y��؏����uKF�㒾���a�a�����Ʀ��m���]��r���1�`�)���_��>Շ�h�}��;k�T�>��1)�q�T���%  $��i<FУ1�<`F����[��!<C_�`V�rw;J�	��N�D�ph����
.�	Z��� L\���zm}n0r�L�=�Gj.,p�    �     P       �   ��������'�%�sz��L��e�a            (�/� U= �  � I  virtual Ipv4Address GetSource(destination) const;

 Aq��=8"    6     p  �     �   ����vm���ׯRN�%�"D���I�            (�/� �= T  	� �
  virtual uint32_t FindInterfaceForAddr (Ipv4ess addr) const;, 
    Mask mask
 Y��"0^�[в��#    �     �  :   	  �   	�����/�`���U^t��z�~2�t            (�/� �� �G�k
3��2})�lrm'���Üa�,��1�4��r�o:�мs�a��9���j��B�A(|�z�6b�ʲ��f�T)��EM����Yr��2mzn�sXa6Ci���H2 $I Nq�IN5�����    +     P  �   
  �   
�����d
�@1R#G�E�"��|�              *  �   D  virtual void SetDefaultMulticastRoute (uint32_t outputInterface);
    {     f  >     �   ����'�fQQog	�@���	              �  �   Z  virtual bool GetIfIndexForDestination (Ipv4Address dest, 
    uint32_t &ifIndex) const;
    �     Y  �     �   ����.��棟/^F�����ڮ��!B            (�/� u� B��� ���%uy'�r�`N��O�ki�y�Ui��x���*�gD�g�9�!wI�YF�����  _Q����V�Ŗ�    	:     S  �     
    �����/\n0g��ZL��M���v              �       Ipv4Impl ();
  *  *   ,
  void SetIpv4 (Ptr<Ipv4L3Protocol> ipv4);
    	�     U       
�   �����H��uv����%)򵬕              
�  
�   I  virtual int32_t FindInterfaceForDevice (Ptr<NetDevice> device) const;

    	�       �        ����$?��I���Čx��K#[��               a   y    